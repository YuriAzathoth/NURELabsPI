using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace PNetKR.Models
{
    [Table("Products")]
    public class Product
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public decimal Price { get; set; }
        public int Available { get; set; }

        public virtual ICollection<Order> Orders { get; set; }
    }
}
