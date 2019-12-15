using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using hw8.DAL;
using hw8.Models;
using hw8.Models.ViewModels;

namespace hw8.Controllers
{
    public class AthletesController : Controller
    {
        private TDBContext db = new TDBContext();

        // GET: Athletes
        public ActionResult Index()
        {
            ViewBag.AthleteID = new SelectList(db.Athletes.Select(a => new { AthleteName = a.Person.Name, AthleteID = a.AthleteID }), "AthleteID", "AthleteName");
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Details([Bind(Include = "AthleteID")] Athlete athlete)
        {
            if (athlete == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Athlete theAthlete = db.Athletes.Find(athlete.AthleteID);
            if (athlete == null)
            {
                return HttpNotFound();
            }
            return View(theAthlete);
        }

        public ActionResult Graph()
        {
            ViewBag.TeamID = new SelectList(db.Teams.Select(t => new { TeamName = t.Name, TeamID = t.TeamID }), "TeamID", "TeamName");
            return View();
        }

        public JsonResult GetAthletes(int? id)
        {
            List<object> data = new List<object>();
            foreach (var item in db.Athletes.Where(a => a.TeamID == id).ToList())
            {
                var obj = new
                {
                    id = item.AthleteID,
                    name = item.Person.Name
                };
                data.Add(obj);
            }
            return Json(data, JsonRequestBehavior.AllowGet);
        }

        public JsonResult GetEvents(int? id)
        {
            List<object> data = new List<object>();
            foreach(var item in db.Results.Where(r => r.AthleteID == id).Select(r => r.Event).Distinct().ToList())
            {
                var obj = new
                {
                    id = item.EventID,
                    name = item.Name
                };
                data.Add(obj);
            }
            return Json(data, JsonRequestBehavior.AllowGet);
        }

        public JsonResult GraphData(int? id, int? athleteID)
        {
            Athlete athlete = db.Athletes.Find(athleteID);
            Event theEvent = db.Events.Find(id);
            if (athlete != null && theEvent != null)
            {
                List<object> data = new List<object>();
                foreach (var item in athlete.Results.Where(r => r.EventID == id).OrderBy(r => r.Meet.Date).ToList())
                {
                    var obj = new
                    {
                        Date = item.Meet.Date.ToShortDateString(),
                        Time = item.Time
                    };
                    data.Add(obj);
                }
                return Json(data, JsonRequestBehavior.AllowGet);
            }
            // No idea how to properly return a json error.
            return Json("Error", JsonRequestBehavior.AllowGet);
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
