/* source: https://codepen.io/yanny-dragnev/pen/oLyadQ?editors=1010 */
$(document).click(function(e) {
	if (!$(e.target).is('.nav-item') && (!$(e.target).is('.navbar')) && (!$(e.target).is('.navba-toggler'))){
		removeBorder(document.getElementById("collapseNav"));
		$('.collapse').collapse('hide');
	}
});