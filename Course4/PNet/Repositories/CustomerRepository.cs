using PNetKR.Models;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;

namespace PNetKR.Repositories
{
    public class CustomerRepository
    {
        public CustomerRepository()
        {
            context.Products.Load();
        }

        public async Task<IEnumerable<Customer>> GetCustomerListAsync()
        {
            return await context.Customers.ToListAsync();
        }

        public async Task<Customer> GetCustomerByIdAsync(int id)
        {
            return await context.Customers.FirstOrDefaultAsync(p => p.Id == id);
        }

        public async Task<IEnumerable<Customer>> GetCustomersByNameAsync(string name)
        {
            return await context.Customers.Where(p => p.FirstName == name || p.LastName == name).ToListAsync();
        }

        public async Task CreateAsync(Customer customer)
        {
            context.Customers.Add(customer);
            await context.SaveChangesAsync();
        }

        public async Task UpdateAsync(Customer customer)
        {
            context.Entry(customer).State = EntityState.Modified;
            await context.SaveChangesAsync();
        }

        public async Task RemoveAsync(Customer customer)
        {
            context.Customers.Remove(customer);
            await context.SaveChangesAsync();
        }

        private ShopContext context = new ShopContext("database.db");
    }
}
