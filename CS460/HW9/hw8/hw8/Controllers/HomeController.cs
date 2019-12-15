using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using hw8.DAL;
using hw8.Models;
using hw8.Models.ViewModels;

namespace hw8.Controllers
{
    public class HomeController : Controller
    {
        private TDBContext db = new TDBContext();

        public ActionResult Index()
        {
            return View();
        }

        // GET: Home/CreateAthlete
        public ActionResult CreateAthlete()
        {
            ViewBag.TeamName = new SelectList(db.Teams.Select(x => x.Name), "TeamName");
            return View();
        }

        // POST: Home/CreateAthlete
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult CreateAthlete([Bind(Include = "AthleteID,AthleteName,TeamName,Gender")] AthleteViewModel athleteViewModel)
        {
            AthleteViewModel temp = athleteViewModel;
            if (ModelState.IsValid)
            {
                Person person = db.People.Where(p => p.Name == athleteViewModel.AthleteName).FirstOrDefault();
                if (person == null)
                {
                    person = new Person
                    {
                        Name = athleteViewModel.AthleteName
                    };
                    db.People.Add(person);
                    person = db.People.Where(p => p.Name == athleteViewModel.AthleteName).FirstOrDefault();
                }
                else
                {
                    ViewBag.PersonError = true;
                    return CreateAthlete();
                }

                Athlete athlete = db.Athletes.Find(athleteViewModel.AthleteID);
                if (athlete == null)
                {
                    athlete = new Athlete();
                }
                athlete.PersonID = db.People.Where(x => x.Name == athleteViewModel.AthleteName).Select(x => x.PersonID).FirstOrDefault();
                athlete.Gender = athleteViewModel.Gender;
                athlete.TeamID = db.Teams.Where(x => x.Name == athleteViewModel.TeamName).Select(x => x.TeamID).FirstOrDefault();
                db.Athletes.Add(athlete);

                db.SaveChanges();
                ViewBag.Error = false;
                return CreateAthlete();
            }
            //ViewBag.TeamID = new SelectList(db.Teams, "TeamID", "Name");
            return View(athleteViewModel);
        }

        // GET: Home/CreateMeet
        public ActionResult CreateMeet()
        {
            return View();
        }

        // POST: Home/CreateMeet
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult CreateMeet([Bind(Include = "MeetID,Location,Date")] Meet meet)
        {
            if (ModelState.IsValid)
            {
                Meet temp = db.Meets.Where(m => m.Location == meet.Location && m.Date == meet.Date).FirstOrDefault();
                if (temp == null)
                {
                    db.Meets.Add(meet);
                }
                else
                {
                    ViewBag.MeetError = true;
                    return CreateMeet();
                }
                db.SaveChanges();
                ViewBag.Error = false;
                return CreateMeet();
            }

            return View(meet);
        }

        // GET: Home/CreateResult
        public ActionResult CreateResult()
        {
            ViewBag.AthleteID = new SelectList(db.Athletes.Select(a => new { AthleteName = a.Person.Name, AthleteID = a.AthleteID }), "AthleteID", "AthleteName");
            ViewBag.MeetID = new SelectList(db.Meets.Select(m => new { MeetLocation = m.Location, MeetID = m.MeetID }), "MeetID", "MeetLocation");
            ViewBag.EventID = new SelectList(db.Events.AsEnumerable().Select(e => new { EventName = string.Format("{0} {1}", e.Gender, e.Name), EventID = e.EventID }), "EventID", "EventName");
            return View();
        }

        // POST: Home/CreateResult
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult CreateResult([Bind(Include = "ResultID,Time,AthleteID,EventID,MeetID")] Result result)
        {
            if (ModelState.IsValid)
            {
                Result temp = db.Results.Where(r => r.AthleteID == result.AthleteID && 
                                               r.EventID == result.EventID && 
                                               r.MeetID == result.MeetID).FirstOrDefault();
                string athleteGender = db.Athletes.Where(a => a.AthleteID == result.AthleteID).Select(a => a.Gender).FirstOrDefault();
                string eventGender = db.Events.Where(e => e.EventID == result.EventID).Select(e => e.Gender).FirstOrDefault();
                if (temp == null && eventGender == athleteGender)
                {
                    db.Results.Add(result);
                }
                else if(eventGender != athleteGender)
                {
                    ViewBag.GenderError = true;
                    return CreateResult();
                }
                else
                {
                    ViewBag.ResultError = true;
                    return CreateResult();
                }
                db.SaveChanges();
                ViewBag.Error = false;
                return CreateResult();
            }
            return View(result);
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