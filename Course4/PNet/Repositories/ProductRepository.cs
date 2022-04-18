using PNetKR.Models;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;

namespace PNetKR.Repositories
{
    public class ProductRepository
    {
        public ProductRepository()
        {
            context.Products.Load();
        }

        public async Task<IEnumerable<Product>> GetProductListAsync()
        {
            return await context.Products.ToListAsync();
        }

        public async Task<Product> GetProductByIdAsync(int id)
        {
            return await context.Products.FirstOrDefaultAsync(p => p.Id == id);
        }

        public async Task<IEnumerable<Product>> GetProductsByNameAsync(string name)
        {
            return await context.Products.Where(p => p.Name == name).ToListAsync();
        }

        public async Task CreateAsync(Product product)
        {
            context.Products.Add(product);
            await context.SaveChangesAsync();
        }

        public async Task UpdateAsync(Product product)
        {
            context.Entry(product).State = EntityState.Modified;
            await context.SaveChangesAsync();
        }

        public async Task RemoveAsync(Product product)
        {
            context.Products.Remove(product);
            await context.SaveChangesAsync();
        }

        private ShopContext context = new ShopContext("database.db");
    }
}
