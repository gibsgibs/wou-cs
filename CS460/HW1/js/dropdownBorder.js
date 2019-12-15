function removeBorder(element) 
{
    if(element.classList.contains("nav-border") && !(element.classList.contains("collapsing")))
    {
        element.classList.remove("nav-border"); 
    }
}

function toggleBorder() 
{
    var element = document.getElementById("collapseNav");
    if(!(element.classList.contains("nav-border")) && !(element.classList.contains("collapsing")))
    {
        element.classList.add("nav-border");
    }
    else
    {
        removeBorder(element);
    }
}

