using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Threading.Tasks;

namespace PNetKR.Pages.Products
{
    public class DetailsModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
                return NotFound();

            Product = await repository.GetProductByIdAsync((int)id);

            if (Product == null)
                return NotFound();

            return Page();
        }

        public Product Product;

        private readonly ProductRepository repository = new ProductRepository();
    }
}
