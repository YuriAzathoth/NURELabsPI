using PNetKR.Models;

namespace PNetKR.Views
{
    public class ProductView
    {
        public ProductView(Product product)
        {
            Id = product.Id;
            Name = product.Name;
        }

        public int Id { get; set; }
        public string Name { get; set; }
    }
}
