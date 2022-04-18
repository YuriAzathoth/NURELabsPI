using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Data.Entity.Infrastructure;
using System.Threading.Tasks;

namespace PNetKR.Pages.Customers
{
    public class DeleteModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id, bool? saveChangesError = false)
        {
            if (id == null)
                return NotFound();

            Customer = await repository.GetCustomerByIdAsync((int)id);
            if (Customer == null)
                return NotFound();

            if (saveChangesError.GetValueOrDefault())
                ErrorMessage = string.Format("Delete {0} failed. Try again", id);

            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null)
                return NotFound();

            var toDelete = await repository.GetCustomerByIdAsync((int)id);
            if (toDelete == null)
                return NotFound();

            try
            {
                await repository.RemoveAsync(toDelete);
                return RedirectToPage("/Customers");
            }
            catch (DbUpdateException)
            {
                return RedirectToAction("/Customers/Delete", new { id, saveChangesError = true });
            }
        }

        [BindProperty]
        public Customer Customer { get; set; }
        public string ErrorMessage { get; set; }

        private readonly CustomerRepository repository = new CustomerRepository();
    }
}
