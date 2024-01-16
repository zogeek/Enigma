var image = document.getElementById('myImage');
var shouldMove = true;

image.addEventListener('mouseover', function() {
    if (shouldMove) {
        setTimeout(function() {
            image.style.position = 'absolute';
            image.style.left = Math.random() * window.innerWidth + 'px';
            image.style.top = Math.random() * window.innerHeight + 'px';
        },200);
    }
});

image.addEventListener('click', function() {
    alert('Tu as réussi !');
    shouldMove = false;

    setTimeout(shouldMove = true, 10000)
});