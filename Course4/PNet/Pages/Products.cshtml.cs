using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace PNetKR.Pages
{
    public class ProductsModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync()
		{
            if (SearchTerm == null)
                Products = await repository.GetProductListAsync();
            else
                Products = await repository.GetProductsByNameAsync(SearchTerm);

            return Page();
		}

        public IEnumerable<Product> Products { get; set; } = new List<Product>();

        [BindProperty(SupportsGet = true)]
        public string SearchTerm { get; set; }

        private readonly ProductRepository repository = new ProductRepository();
    }
}
