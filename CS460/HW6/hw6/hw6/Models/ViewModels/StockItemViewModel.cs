using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Linq;
using System.Data.Entity.Spatial;

namespace hw6.Models.ViewModels
{
    public class DetailsViewModel
    {
        public DetailsViewModel(StockItem stockItem)
        {
            // These items are for the "Stock Item" card.
            StockItemName = stockItem.StockItemName;
            Size = stockItem.Size;
            RecommendedRetailPrice = String.Format("{0:C2}", stockItem.RecommendedRetailPrice);
            TypicalWeightPerUnit = stockItem.TypicalWeightPerUnit;
            LeadTimeDays = String.Format("{0} days", stockItem.LeadTimeDays);
            Photo = stockItem.Photo;
            ValidFrom = GetDate(stockItem.ValidFrom);
            CountryOfOrigin = GetCountryOfOrigin(stockItem.CustomFields);
            Tags = GetTags(stockItem.CustomFields);

            // These items are for the "Supplier Profile" card.
            SupplierName = stockItem.Supplier.SupplierName;
            SupplierPhoneNumber = stockItem.Supplier.PhoneNumber;
            SupplierFaxNumber = stockItem.Supplier.FaxNumber;
            SupplierWebsiteURL = stockItem.Supplier.WebsiteURL;
            SupplierContact = stockItem.Supplier.Person2.FullName;

            // These items are for the "Top Purchasers" card.
            // I had help with this query from Tiffany J.
            TopCustomersByOrder = stockItem.InvoiceLines
                                           .GroupBy(il => il.Invoice.Customer.CustomerName)
                                           .OrderByDescending(grp => grp.Select(il => il.Quantity).Sum())
                                           .Take(10)
                                           .Select(grp => Tuple.Create(grp.First().Invoice.Customer.CustomerName, grp.Select(il => il.Quantity).Sum())).ToList();


            // These items are for the "Sales History Summary" card.
            Orders = stockItem.InvoiceLines.Select(il => il.Quantity).Count();
            GrossSales = String.Format("{0:C2}", stockItem.InvoiceLines.Select(il => il.ExtendedPrice).Sum());
            GrossProfit = String.Format("{0:C2}", stockItem.InvoiceLines.Select(li => li.LineProfit).Sum());

            // Google Maps API stuff.
            Key = System.Web.Configuration.WebConfigurationManager.AppSettings["GoogleMapsAPIKey"];
            Location = GetLocation(stockItem.Supplier.DeliveryLocation);
            
        }

        // These items are for the "Stock Item" card.
        public string GetCountryOfOrigin(string customFields)
        {
            JObject json = JObject.Parse(customFields);
            return json.Value<string>("CountryOfManufacture");
        }

        public string GetTags(string customFields)
        {
            JObject json = JObject.Parse(customFields);
            JArray jArray = json.Value<JArray>("Tags");
            string tags = "";
            foreach (var item in jArray)
            {
                tags += $"{item} ";
            }
            return tags;
        }

        public string GetDate(DateTime validFrom)
        {
            return validFrom.ToShortDateString();
        }

        [Required]
        [StringLength(100)]
        [Display(Name = "Stock Item Name")]
        public string StockItemName { get; private set; }

        [StringLength(20)]
        [Display(Name = "Item size")]
        public string Size { get; private set; }

        [Display(Name = "Recommended Retail Price")]
        public string RecommendedRetailPrice { get; private set; }

        [Display(Name = "Weight Per Unit")]
        public decimal TypicalWeightPerUnit { get; private set; }

        [Display(Name = "Lead Time")]
        public string LeadTimeDays { get; private set; }

        [Display(Name = "Photograph")]
        public byte[] Photo { get; private set; }

        [DatabaseGenerated(DatabaseGeneratedOption.Computed)]
        [Display(Name = "Tags")]
        public string Tags { get; private set; }

        [Column(TypeName = "datetime2")]
        [Display(Name = "Valid since")]
        public string ValidFrom { get; private set; }

        [Display(Name = "Country of Origin")]
        public string CountryOfOrigin { get; private set; }

        // These items are for the "Supplier Profile" card.
        [Required]
        [StringLength(100)]
        [Display(Name = "Company")]
        public string SupplierName { get; private set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "Phone Number")]
        public string SupplierPhoneNumber { get; private set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "Fax Number")]
        public string SupplierFaxNumber { get; private set; }

        [Required]
        [StringLength(256)]
        [Display(Name = "Website")]
        public string SupplierWebsiteURL { get; private set; }

        [StringLength(50)]
        [Display(Name = "Contact")]
        public string SupplierContact { get; private set; }

        // These items are for the "Top Purchasers" card.
        [Display(Name = "Customers")]
        public List<Tuple<string, int>> TopCustomersByOrder { get; private set; }

        // These items are for the "Sales History Summary" card.
        [Display(Name = "Orders")]
        public int Orders { get; private set; }

        [Display(Name = "Gross Sales")]
        public string GrossSales { get; private set; }

        [Display(Name = "Gross Profit")]
        public string GrossProfit { get; private set; }

        

        // For the Google Maps API
        public Tuple<double, double> GetLocation(DbGeography dbGeography)
        {
            double latitude = (double)dbGeography.Latitude;
            double longitude = (double)dbGeography.Longitude;
            Tuple<double, double> result = new Tuple<double, double>(latitude, longitude);
            return result;
        }

        public Tuple<double,double> Location { get; private set; }

        public string Key { get; private set; }
    }
}