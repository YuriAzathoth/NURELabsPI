using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using PNetKR.Views;
using System.Data.Entity.Infrastructure;
using System.Threading.Tasks;

namespace PNetKR.Pages.Orders
{
    public class DeleteModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id, bool? saveChangesError = false)
        {
            if (id == null)
                return NotFound();

            var OrderModel = await repository.GetOrderByIdAsync((int)id);
            Order = new OrderView(OrderModel);
            if (Order == null)
                return NotFound();

            if (saveChangesError.GetValueOrDefault())
                ErrorMessage = string.Format("Delete {0} failed. Try again", id);

            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null)
                return NotFound();

            var toDelete = await repository.GetOrderByIdAsync((int)id);
            if (toDelete == null)
                return NotFound();

            try
            {
                await repository.RemoveAsync(toDelete);
                return RedirectToPage("/Orders");
            }
            catch (DbUpdateException)
            {
                return RedirectToAction("/Orders/Delete", new { id, saveChangesError = true });
            }
        }

        [BindProperty]
        public OrderView Order { get; set; }
        public string ErrorMessage { get; set; }

        private readonly OrderRepository repository = new OrderRepository();
    }
}
