using PNetKR.Models;
using System.Data.Entity;
using System.Data.Entity.ModelConfiguration.Conventions;
using System.Data.SQLite;

namespace PNetKR
{
    public class ShopContext : DbContext
    {
        public ShopContext(string filename) :
            base (new SQLiteConnection()
            {
                ConnectionString = new SQLiteConnectionStringBuilder()
                {
                    DataSource = filename,
                    ForeignKeys = true
                }.ConnectionString
            }, true)
        {
        }

        public void LoadCustomers()
        {
            Customers.Load();
        }

        public void LoadProducts()
        {
            Products.Load();
        }

        public void LoadOrders()
        {
            Orders.Load();
        }

        public DbSet<Customer> Customers { get; set; }
        public DbSet<Product> Products { get; set; }
        public DbSet<Order> Orders { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Conventions.Remove<PluralizingTableNameConvention>();
            base.OnModelCreating(modelBuilder);
        }
    }
}
