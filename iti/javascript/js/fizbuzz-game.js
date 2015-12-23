function fuzzbuzz(x) {
	var result = "";
	if (x % 3 === 0) result += 'Fuzz';
	if (x % 5 === 0) result += 'Buzz';
	return result;
}