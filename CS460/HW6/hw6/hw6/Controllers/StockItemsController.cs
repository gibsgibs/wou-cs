using System.Data;
using System.Linq;
using System.Net;
using System.Web.Mvc;
using hw6.Models;
using hw6.Models.ViewModels;

namespace hw6.Controllers
{
    public class StockItemsController : Controller
    {
        private WWIContext db = new WWIContext();

        [HttpGet]
        public ActionResult Index(string userSearch)
        {
            if (userSearch != null)
            {
                var names = db.StockItems.Where(si => si.StockItemName.Contains(userSearch)).ToList();
                if (names.Count() == 0)
                {
                    ViewBag.success = false;
                }
                return View(names);
            }
            else
            {
                return View();
            }
        }

        // GET: StockItems/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            StockItem stockItem = db.StockItems.Find(id);
            if (stockItem == null)
            {
                return HttpNotFound();
            }
            DetailsViewModel detailsViewModel = new DetailsViewModel(stockItem);
            return View(detailsViewModel);
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
