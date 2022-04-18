using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using PNetKR.Models;
using PNetKR.Repositories;
using PNetKR.Views;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace PNetKR.Pages.Customers
{
    public class OrdersModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? customerId)
        {
            IEnumerable<Order> Models = new List<Order>();
            if (customerId != null)
                Models = await repository.GetOrdersByCustomerIdAsync((int)customerId);
            else
                Models = await repository.GetOrderListAsync();
            foreach (var model in Models)
                ((List<OrderView>)Orders).Add(new OrderView(model));

            return Page();
        }

        public IEnumerable<OrderView> Orders = new List<OrderView>();

        private readonly OrderRepository repository = new OrderRepository();
    }
}
