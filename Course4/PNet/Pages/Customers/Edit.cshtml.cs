using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Threading.Tasks;

namespace PNetKR.Pages.Customers
{
    public class EditModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id != null)
            {
                Customer = await repository.GetCustomerByIdAsync((int)id);
                if (Customer == null)
                    return NotFound();
            }
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id != null)
            {
                var toUpdate = await repository.GetCustomerByIdAsync((int)id);
                if (toUpdate == null)
                    return NotFound();

                if (await TryUpdateModelAsync(toUpdate, "customer", s => s.FirstName, s => s.LastName, s => s.Email, s => s.Phone))
                {
                    await repository.UpdateAsync(toUpdate);
                    return RedirectToPage("/Customers");
                }
            }
            else
            {
                var toAdd = new Customer();
                if (await TryUpdateModelAsync(toAdd, "customer", s => s.FirstName, s => s.LastName, s => s.Email, s => s.Phone))
                {
                    await repository.CreateAsync(toAdd);
                    return RedirectToPage("/Customers");
                }
            }
            return Page();
        }

        public Customer Customer { get; set; }

        private readonly CustomerRepository repository = new CustomerRepository();
    }
}
