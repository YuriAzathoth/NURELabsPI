using PNetKR.Models;

namespace PNetKR.Views
{
    public class OrderView
    {
        public OrderView()
        {
        }

        public OrderView(Order order)
        {
            Id = order.Id;
            Customer = order.Customer.FirstName + " " + order.Customer.LastName;
            Count = order.Count;
            Price = order.Price;
            Date = order.Date;
            Time = order.Time;
        }

        public int Id { get; set; }
        public string Customer { get; set; }
        public string Product { get; set; }
        public int Count { get; set; }
        public decimal Price { get; set; }
        public string Date { get; set; }
        public string Time { get; set; }
    }
}
