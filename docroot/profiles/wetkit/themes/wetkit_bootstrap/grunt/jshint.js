module.exports = {
	/**
	 * grunt-contrib-jshint
	 *
	 * Validate files with JSHint.
	 *
	 * @link https://www.npmjs.com/package/grunt-contrib-jshint
	 */
	options: {
		curly: true,
		eqeqeq: true,
		eqnull: true,
		browser: true,
		globals: {
			jQuery: true
		}
	},
	all: [
		'Gruntfile.js',
		'assets/js/src/**/*.js'
	]
};
