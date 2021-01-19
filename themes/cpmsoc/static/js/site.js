(function() {
  document.querySelectorAll('.navbar-burger[role="button"]').forEach(function(e) {
    e.addEventListener('click', function() {
      document.getElementById(e.dataset.target).classList.toggle('is-active');
    });
  });
})()
