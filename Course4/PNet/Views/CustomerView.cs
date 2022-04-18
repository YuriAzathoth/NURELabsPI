using PNetKR.Models;

namespace PNetKR.Views
{
    public class CustomerView
    {
        public CustomerView(Customer customer)
        {
            Id = customer.Id;
            FullName = customer.FirstName + " " + customer.LastName;
        }

        public int Id { get; set; }
        public string FullName { get; set; }
    }
}
