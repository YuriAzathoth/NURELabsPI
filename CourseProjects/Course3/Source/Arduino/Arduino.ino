#include <stdint.h>
#include <string.h>

#define FIELD_ID 1254
#define EMAIL "e@t.com"
#define PASSWORD "11"

#define LOOP_PERIOD 50
#define TIME_TO_RESET 5000

#define PIN_MEASURER A0
#define PIN_INDICATOR_IRRIGATE 2
#define PIN_INDICATOR_DRAIN 3
#define PIN_INDICATOR_CONFIGURED 13

template<typename _Data>
union net_object
{
  _Data data;
  uint8_t buffer[sizeof(data)];

  bool verify_checksum() const noexcept { return data.checksum == data.get_checksum(); }
  void set_checksum() noexcept { data.checksum = data.get_checksum(); }
};

struct init_s
{
  char email[32];
  char password[32];
  uint32_t id;
  uint8_t checksum;

  uint8_t get_checksum() const noexcept
  {
    uint8_t sum = 0;
    for (uint8_t i = 0; i < 16; ++i)
      sum ^= (uint8_t)id;
    for (uint8_t i = 0; i < 32; ++i)
      sum ^= email[i] ^ password[i];
    return sum;
  }
};

struct config_s
{
  uint8_t hmin;
  uint8_t hmax;
  uint8_t checksum;

  uint8_t get_checksum() const noexcept { return hmin ^ hmax; }
};

struct response_s
{
  uint32_t id;
  uint8_t humidity;
  uint8_t checksum;

  uint8_t get_checksum() const noexcept
  {
    return humidity ^ (uint8_t)id;
  }
};

bool configure();
void measure();
void (*reset)() = 0;

net_object<init_s> initd;
net_object<config_s> config;
net_object<response_s> response;

int length = 0;
uint8_t result = 0;
bool configured = false;

void setup()
{
  pinMode(PIN_MEASURER, INPUT);
  pinMode(PIN_INDICATOR_IRRIGATE, OUTPUT);
  pinMode(PIN_INDICATOR_DRAIN, OUTPUT);
  pinMode(PIN_INDICATOR_CONFIGURED, OUTPUT);

  digitalWrite(PIN_INDICATOR_IRRIGATE, 0);
  digitalWrite(PIN_INDICATOR_DRAIN, 0);
  digitalWrite(PIN_INDICATOR_CONFIGURED, 0);

  Serial.begin(9600);
  
  initd.data.id = FIELD_ID;
  response.data.id = FIELD_ID;
  strcpy(initd.data.email, EMAIL);
  strcpy(initd.data.password, PASSWORD);
}

void loop()
{
  if (!configured)
    configure();
  else
    measure();
  delay(LOOP_PERIOD);
}

bool configure()
{
  Serial.write(initd.buffer, sizeof(initd.buffer));

  length = Serial.readBytes(config.buffer, sizeof(config.buffer));
  configured = length && config.verify_checksum();
}

void measure()
{
  response.data.humidity = (uint8_t)((float)analogRead(PIN_MEASURER) / 2.55f);
  response.set_checksum();
  Serial.write(response.buffer, sizeof(response.buffer));

  result = Serial.read();
  if (result == '\t')
  {
    configured = false;
    digitalWrite(PIN_INDICATOR_IRRIGATE, response.data.humidity < config.data.hmin);
    digitalWrite(PIN_INDICATOR_DRAIN, response.data.humidity > config.data.hmax);
    digitalWrite(PIN_INDICATOR_CONFIGURED, 1);

    delay(TIME_TO_RESET);

    (*reset)();
  }
}
