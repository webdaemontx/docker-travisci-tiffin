module.exports = {
	'default': [
		'styles',
		// 'scripts',
		'notify:default'
	],
	'styles': [
		// 'clean:pre',
		'sass',
		'postcss:dev',
		'notify:styles'
	],
	'scripts': [
		'jshint',
		'concat',
		'notify:scripts'
	],
	'build': [
		// 'clean',
		'default',
		'postcss:build',
		// 'uglify',
		// 'copy:main',
		// 'compress',
		'notify:build'
	],
	'server': [
		'browserSync',
		'watch'
	]
};
