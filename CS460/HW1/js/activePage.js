/* Did not wrtie this script. Makes the current page 'active' */
$(function()
{
    $('a').each(function()
    {
        if ($(this).prop('href') == window.location.href)
        {
            $(this).addClass('active'); 
        }
    });
});