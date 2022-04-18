using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.JSInterop;
using PNetKR.Models;
using PNetKR.Repositories;
using PNetKR.Views;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace PNetKR.Pages.Orders
{
    public class EditModel : PageModel
    {
        public async Task<IActionResult> OnGetAsync(int? id)
        {
            var customers = await customerRepository.GetCustomerListAsync();
            foreach (var customer in customers)
                ((List<CustomerView>)Customers).Add(new CustomerView(customer));

            var products = await productRepository.GetProductListAsync();
            foreach (var product in products)
                ((List<ProductView>)Products).Add(new ProductView(product));

            if (id != null)
            {
                var Order = await orderRepository.GetOrderByIdAsync((int)id);
                if (Order == null)
                    return NotFound();
            }
            else
                Order = new Order();
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id != null)
            {
                var toUpdate = await orderRepository.GetOrderByIdAsync((int)id);
                if (toUpdate == null)
                    return NotFound();

                if (await TryUpdateModelAsync(toUpdate, "order", s => s.CustomerId, s => s.ProductId, s => s.Count, s => s.Price, s => s.Date, s => s.Time))
                {
                    await orderRepository.UpdateAsync(toUpdate);
                    return RedirectToPage("/Orders");
                }
            }
            else
            {
                var toAdd = new Order();
                if (await TryUpdateModelAsync(toAdd, "order", s => s.CustomerId, s => s.ProductId, s => s.Count, s => s.Price, s => s.Date, s => s.Time))
                {
                    await orderRepository.CreateAsync(toAdd);
                    return RedirectToPage("/Orders");
                }
            }
            return Page();
        }

        public Order Order { get; set; }
        [BindProperty]
        public int CustomerId { get; set; }
        [BindProperty]
        public int ProductId { get; set; }
        public IEnumerable<CustomerView> Customers { get; set; } = new List<CustomerView>();
        public IEnumerable<ProductView> Products { get; set; } = new List<ProductView>();

        private readonly CustomerRepository customerRepository = new CustomerRepository();
        private readonly OrderRepository orderRepository = new OrderRepository();
        private readonly ProductRepository productRepository = new ProductRepository();
    }
}
