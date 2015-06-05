var timer = function(func, args) {
    var startTime = new Date();
    var results = func(args);
    var endTime = new Date();
    console.log('Time used: ' + (endTime.getTime() - startTime.getTime()) + ' milliseconds');
    return results;
}

