var sum =function(N){
	var multiple = 0;
	for(var i = 1; i< N; i++){
		if(i%3 == 0 || i%5 == 0){
			multiple += i;
		}
	}
	return multiple;
}
console.log(sum(1000));