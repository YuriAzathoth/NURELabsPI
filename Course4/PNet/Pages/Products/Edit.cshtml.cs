using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Threading.Tasks;

namespace PNetKR.Pages.Products
{
    public class EditModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id != null)
            {
                Product = await repository.GetProductByIdAsync((int)id);
                if (Product == null)
                    return NotFound();
            }
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id != null)
            {
                var toUpdate = await repository.GetProductByIdAsync((int)id);
                if (toUpdate == null)
                    return NotFound();

                if (await TryUpdateModelAsync(toUpdate, "product", s => s.Name, s => s.Price, s => s.Available))
                {
                    await repository.UpdateAsync(toUpdate);
                    return RedirectToPage("/Products");
                }
            }
            else
            {
                var toAdd = new Product();
                if (await TryUpdateModelAsync(toAdd, "product", s => s.Name, s => s.Price, s => s.Available))
                {
                    await repository.CreateAsync(toAdd);
                    return RedirectToPage("/Products");
                }
            }
            return Page();
        }

        public Product Product { get; set; }

        private readonly ProductRepository repository = new ProductRepository();
    }
}
