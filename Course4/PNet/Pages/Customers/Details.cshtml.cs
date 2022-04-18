using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Threading.Tasks;

namespace PNetKR.Pages.Customers
{
    public class DetailsModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
                return NotFound();

            Customer = await repository.GetCustomerByIdAsync((int)id);

            if (Customer == null)
                return NotFound();

            return Page();
        }

        public Customer Customer;

        private readonly CustomerRepository repository = new CustomerRepository();
    }
}
