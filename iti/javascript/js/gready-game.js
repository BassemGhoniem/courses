function greedy (money) {
	var cents = Math.round(100 * money);
	var aval = [100, 25, 10, 5, 1];
	var avalCoins = [' Dollar', ' Quarter', ' Dime', ' Nickale', ' Cent'];
	for (var i = 0; i < aval.length; i++) {
		console.log(Number.parseInt(cents / aval[i]) + avalCoins[i]);
		cents %= aval[i];
	}
}