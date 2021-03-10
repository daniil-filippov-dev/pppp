describe("Решения системы (a*x+b*y=e)&&(c*x+d*y=f)", function() {

	it(`все 0 выдаст '5'`, function() {
		assert.equal(main(0, 0, 0, 0, 0, 0), '5')
	});
	it(`все ' ' выдаст '5', ожидалось 'Are you kidding me?' js приводит пустую строчку к 0`, function() {
		assert.equal(main(' ', ' ', ' ', ' ', ' ', ' '), 'Are you kidding me?')
	});
	it(`все null выдаст "Are you kidding me?"`, function() {
		assert.equal(main(null, null, null, null, null, null), "Are you kidding me?")
	});
	it(` для 2x+2y=5 && 5x+6y=4 ожидаем '2 11 -8.5'`, function() {
		assert.equal(main(2, 2, 5, 6, 5, 4), '2 11 -8.5')
	})
	it(` для 2x+0y=0 && 4x+0y=4 ожидаем '0' система не имеет решений`, function() {
		assert.equal(main(2, 0, 4, 0, 0, 4), '0')
	})
	it(` для -4x+8y=2 && -4x+8y=2 ожидаем '1 0.5 0.25' система имеет бесконечное множество решений`, function() {
		assert.equal(main(-4, 8, -4, 8, 2, 2), '1 0.5 0.25')
	})
	it(` для 0x+0y=0 && 0x+8y=2 ожидаем '4 0.25' система имеет бесконечное множество решений`, function() {
		assert.equal(main(0, 0, 0, 8, 0, 2), '4 0.25')
	})
	it(` для 1x+0y=2 && 0x+0y=0 ожидаем '3 2' система имеет бесконечное множество решений`, function() {
		assert.equal(main(1, 0, 0, 0, 2, 0), '3 2')
	})
	
});