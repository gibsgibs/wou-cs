using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace HW4.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }
        [HttpGet]
        public ActionResult RGBColor()
        {
            if(Request.QueryString["redValue"] != null && Request.QueryString["greenValue"] != null && Request.QueryString["blueValue"] != null)
            {
                ViewBag.success = true;
            }
            int.TryParse(Request.QueryString["redValue"], out int redValue);
            int.TryParse(Request.QueryString["greenValue"], out int greenValue);
            int.TryParse(Request.QueryString["blueValue"], out int blueValue);

            string red = redValue.ToString("X");
            string green = greenValue.ToString("X");
            string blue = blueValue.ToString("X");

            // These conditionals place a "0" infront of any single digit hex value.
            if (red.Length == 1)
            {
                red = "0" + red;
            }
            if (green.Length == 1)
            {
                green = "0" + green;
            }
            if (blue.Length == 1)
            {
                blue = "0" + blue;
            }

            string color = red + green + blue;

            ViewBag.hexValue = "#" + color;

            // For setting the placeholders if the value was not 0.
            if(redValue != 0)
            {
                ViewBag.red = redValue;
            }
            if(greenValue !=0)
            {
                ViewBag.green = greenValue;
            }
            if (blueValue != 0)
            {
                ViewBag.blue = blueValue;
            }

            return View();
        }
    }
}