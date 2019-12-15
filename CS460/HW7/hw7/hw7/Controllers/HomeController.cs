using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.IO;
using System.Net;
using hw7.Models;
using System.Diagnostics;

namespace hw7.Controllers
{
    public class HomeController : Controller
    {
        private static readonly string _key = System.Web.Configuration.WebConfigurationManager.AppSettings["githubPAT"];
        private static readonly string _username = System.Web.Configuration.WebConfigurationManager.AppSettings["githubUsername"];

        public ActionResult Index()
        {
            GithubUser githubUser = GetGithubUser();
            githubUser.githubRepos = GetGithubRepos();
            return View(githubUser);
        }

        private GithubUser GetGithubUser()
        {
            var json = SendRequest("https://api.github.com/user", _key, _username);
            JObject jObject = JObject.Parse(json);
            GithubUser githubUser = new GithubUser(jObject);
            return githubUser;
        }

        private List<GithubRepo> GetGithubRepos()
        {
            var json = SendRequest("https://api.github.com/user/repos?sort=updated", _key, _username);
            JArray jArray = JArray.Parse(json);
            List<GithubRepo> githubRepos = new List<GithubRepo>();
            foreach(var item in jArray)
            {
                GithubRepo githubRepo = new GithubRepo(item);
                githubRepos.Add(githubRepo);
            }
            return githubRepos;
        }

        // For use later. Just testing for now.
        public JsonResult Commits(string user, string repo)
        {
            var json = SendRequest($"https://api.github.com/repos/{user}/{repo}/commits", _key, _username);
            JArray jArray = JArray.Parse(json);
            List<object> data = new List<object>();
            foreach (JToken item in jArray)
            {
                var obj = new
                {
                    sha = (string)item["sha"],
                    date = (string)item["commit"]["committer"]["date"],
                    name = (string)item["commit"]["committer"]["name"],
                    html_url = (string)item["html_url"],
                    message = (string)item["commit"]["message"]
                };
                data.Add(obj);
            }
            return Json(data, JsonRequestBehavior.AllowGet);
        }

        // Method provided by Dr. Morse.
        private string SendRequest(string uri, string credentials, string username)
        {
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(uri);
            request.Headers.Add("Authorization", "token " + credentials);
            // Required, see: https://developer.github.com/v3/#user-agent-required.
            request.UserAgent = username;       
            request.Accept = "application/json";

            string jsonString = null;
            try
            {
                using (WebResponse response = request.GetResponse())
                {
                    Stream stream = response.GetResponseStream();
                    StreamReader reader = new StreamReader(stream);
                    jsonString = reader.ReadToEnd();
                    reader.Close();
                    stream.Close();
                }
                return jsonString;
            }
            catch(Exception)
            {
                return "";
            }
        }
    }
}