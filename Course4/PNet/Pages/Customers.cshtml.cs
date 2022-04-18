using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace PNetKR.Pages
{
    public class CustomersModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync()
		{
            if (SearchTerm == null)
                Customers = await repository.GetCustomerListAsync();
            else
                Customers = await repository.GetCustomersByNameAsync(SearchTerm);

            return Page();
		}

        public IEnumerable<Customer> Customers { get; set; } = new List<Customer>();

        [BindProperty(SupportsGet = true)]
        public string SearchTerm { get; set; }

        private readonly CustomerRepository repository = new CustomerRepository();
    }
}
