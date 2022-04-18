using PNetKR.Models;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;

namespace PNetKR.Repositories
{
    public class OrderRepository
    {
        public OrderRepository()
        {
            context.Orders.Load();
        }

        public async Task<IEnumerable<Order>> GetOrderListAsync()
        {
            return await context.Orders.ToListAsync();
        }

        public async Task<Order> GetOrderByIdAsync(int id)
        {
            return await context.Orders.FirstOrDefaultAsync(p => p.Id == id);
        }

        public async Task<IEnumerable<Order>> GetOrdersByCustomerIdAsync(int customerId)
        {
            return await context.Orders.Where(p => p.CustomerId == customerId).ToListAsync();
        }

        public async Task CreateAsync(Order order)
        {
            context.Orders.Add(order);
            await context.SaveChangesAsync();
        }

        public async Task UpdateAsync(Order order)
        {
            context.Entry(order).State = EntityState.Modified;
            await context.SaveChangesAsync();
        }

        public async Task RemoveAsync(Order order)
        {
            context.Orders.Remove(order);
            await context.SaveChangesAsync();
        }

        private ShopContext context = new ShopContext("database.db");
    }
}
