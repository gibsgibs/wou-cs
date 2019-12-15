using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using FinalProject.DAL;
using FinalProject.Models;

namespace FinalProject.Controllers
{
    public class RSVPsController : Controller
    {
        private FDBContext db = new FDBContext();

        // GET: RSVPs
        public ActionResult Index()
        {
            var rSVPs = db.RSVPs.Include(r => r.Event).Include(r => r.Person);
            return View(rSVPs.ToList());
        }

        // GET: RSVPs/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            RSVP rSVP = db.RSVPs.Find(id);
            if (rSVP == null)
            {
                return HttpNotFound();
            }
            return View(rSVP);
        }

        // GET: RSVPs/Create
        public ActionResult Create()
        {
            ViewBag.EventName = new SelectList(db.Events, "EventID", "Title");
            ViewBag.PersonAttending = new SelectList(db.People.OrderBy(p => p.LastName).Select(p => new { PersonID = p.PersonID, Name = p.FirstName + " " + p.LastName}), "PersonID", "Name");
            return View();
        }

        // POST: RSVPs/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "RSVPID,EventName,PersonAttending,TimeStamp")] RSVP rSVP)
        {
            if (ModelState.IsValid)
            {
                rSVP.TimeStamp = DateTime.Now;
                db.RSVPs.Add(rSVP);
                db.SaveChanges();
                return RedirectToAction("Index", "Home");
            }

            ViewBag.EventName = new SelectList(db.Events, "EventID", "Title", rSVP.EventName);
            ViewBag.PersonAttending = new SelectList(db.People, "PersonID", "FirstName", rSVP.PersonAttending);
            return View(rSVP);
        }

        // GET: RSVPs/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            RSVP rSVP = db.RSVPs.Find(id);
            if (rSVP == null)
            {
                return HttpNotFound();
            }
            ViewBag.EventName = new SelectList(db.Events, "EventID", "Title", rSVP.EventName);
            ViewBag.PersonAttending = new SelectList(db.People, "PersonID", "FirstName", rSVP.PersonAttending);
            return View(rSVP);
        }

        // POST: RSVPs/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "RSVPID,EventName,PersonAttending,TimeStamp")] RSVP rSVP)
        {
            if (ModelState.IsValid)
            {
                db.Entry(rSVP).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.EventName = new SelectList(db.Events, "EventID", "Title", rSVP.EventName);
            ViewBag.PersonAttending = new SelectList(db.People, "PersonID", "FirstName", rSVP.PersonAttending);
            return View(rSVP);
        }

        // GET: RSVPs/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            RSVP rSVP = db.RSVPs.Find(id);
            if (rSVP == null)
            {
                return HttpNotFound();
            }
            return View(rSVP);
        }

        // POST: RSVPs/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            RSVP rSVP = db.RSVPs.Find(id);
            db.RSVPs.Remove(rSVP);
            db.SaveChanges();
            return RedirectToAction("Index");
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
