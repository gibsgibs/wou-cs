using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Text.RegularExpressions;
using System.Drawing;

namespace HW4.Controllers
{
    public class ColorInterpolatorController : Controller
    {
        public static void ColorToHSV(Color color, out double hue, out double saturation, out double value)
        {
            int max = Math.Max(color.R, Math.Max(color.G, color.B));
            int min = Math.Min(color.R, Math.Min(color.G, color.B));

            hue = color.GetHue();
            saturation = (max == 0) ? 0 : 1d - (1d * min / max);
            value = max / 255d;
        }

        public static Color ColorFromHSV(double hue, double saturation, double value)
        {
            int hi = Convert.ToInt32(Math.Floor(hue / 60)) % 6;
            double f = hue / 60 - Math.Floor(hue / 60);

            value = value * 255;
            int v = Convert.ToInt32(value);
            int p = Convert.ToInt32(value * (1 - saturation));
            int q = Convert.ToInt32(value * (1 - f * saturation));
            int t = Convert.ToInt32(value * (1 - (1 - f) * saturation));

            if (hi == 0)
                return Color.FromArgb(255, v, t, p);
            else if (hi == 1)
                return Color.FromArgb(255, q, v, p);
            else if (hi == 2)
                return Color.FromArgb(255, p, v, t);
            else if (hi == 3)
                return Color.FromArgb(255, p, q, v);
            else if (hi == 4)
                return Color.FromArgb(255, t, p, v);
            else
                return Color.FromArgb(255, v, p, q);
        }

        string ConvertTo6Digit(string color)
        {
            string newColor;
            color = color.Substring(1);
            if (color.Length == 3)
            {
                newColor = "#" + string.Concat(color[0], color[0], color[1], color[1], color[2], color[2]);
            }
            else
            {
                newColor = "#" + color;
            }
            return newColor;
        }

        // GET: ColorInterpolator
        public ActionResult Create()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Create(string startingColor, string endingColor, int? numberOfRows)
        {
            ViewBag.Success = false;
            ViewBag.numberOfRows = numberOfRows;

            Regex hexColor = new Regex(@"^#(?:[0-9A-F]{3}){1,2}$");

            if (hexColor.IsMatch(startingColor) && hexColor.IsMatch(endingColor) && numberOfRows > 1)
            {
                startingColor = ConvertTo6Digit(startingColor);
                endingColor = ConvertTo6Digit(endingColor);

                ColorToHSV(ColorTranslator.FromHtml(startingColor), out double startHue, out double startSat, out double startVal);
                ColorToHSV(ColorTranslator.FromHtml(endingColor), out double endHue, out double endSat, out double endVal);

                if (startingColor == "#000000" || startingColor == "#000")
                {
                    startHue = endHue;
                }
                if (endingColor == "#000000" || startingColor == "#000")
                {
                    endHue = startHue;
                }
                if (startingColor == "#FFFFFF" || startingColor == "#FFF")
                {
                    startHue = endHue;
                }
                if (endingColor == "#FFFFFF" || endingColor == "#FFF")
                {
                    endHue = startHue;
                }

                double hueStep = (endHue - startHue) / (double)(numberOfRows - 1);
                double satStep = (endSat - startSat) / (double)(numberOfRows - 1);
                double valStep = (endVal - startVal) / (double)(numberOfRows - 1);

                double currentHue = startHue;
                double currentSat = startSat;
                double currentVal = startVal;

                List<string> colors = new List<string>();

                colors.Add(startingColor);

                for (int i = 0; i < numberOfRows - 1; i++)
                {
                    currentHue += hueStep;
                    currentSat += satStep;
                    currentVal += valStep;

                    Color nextColor = ColorFromHSV(currentHue, currentSat, currentVal);
                    colors.Add(ColorTranslator.ToHtml(nextColor));               
                }
                ViewBag.Success = true;
                ViewBag.list = colors;
                return View();
            }
            else
            {
                return View();
            }
        }
    }
}