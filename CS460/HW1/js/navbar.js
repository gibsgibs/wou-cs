/* adds the navbar to each page the script is called in */
document.getElementById("navbar").innerHTML = 
'<nav class="navbar navbar-expand-xl text-center bg-gray shadow">'+
'<button class="navbar-toggler btn-blue" onclick="toggleBorder()" type="button" data-toggle="collapse" data-target="#collapseNav">'+
'<span class="oi oi-menu"></span>'+
'</button>'+
'<span class="navbar-brand"><i>Geozone</i></span>'+
'<div id="collapseNav" class="collapse navbar-collapse mr-auto">'+
'<ul class="navbar-nav mr-auto">'+
'<li class="nav-item">'+
'<a class="nav-link" href="../html/index.html"><span class="oi oi-home"></span>Home</a>'+
'</li>'+
'<li class="nav-item">'+
'<a class="nav-link" href="../html/mohs.html">Moh\'s Scale</a>'+
'</li>'+
'<li class="nav-item">'+
'<a class="nav-link" href="../html/igneous.html">Igneous</a>'+
'</li>'+
'<li class="nav-item">'+
'<a class="nav-link" href="../html/sedimentary.html">Sedimentary</a>'+
'</li>'+
'<li class="nav-item">'+
'<a class="nav-link" href="../html/metamorphic.html">Metamorphic</a>'+
'</li>'+
'</ul>'+
'</div>'+
'</nav>';

document.getElementById("footer").innerHTML = '<i>Geozone</i> - &copy ' + new Date().getFullYear() + ' All Rights Reserved';