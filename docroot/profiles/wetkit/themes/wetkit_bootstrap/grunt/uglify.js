module.exports = {
	/**
	 * grunt-contrib-uglify
	 *
	 * Minify JavaScript files with UglifyJS
	 *
	 * @link https://www.npmjs.com/package/grunt-contrib-uglify
	 */
	options: {
		mangle: {
			except: ['jQuery']
		},
		banner: '/*! <%= package.title %>\n' +
		' * <%= package.homepage %>\n' +
		' * Copyright (c) <%= grunt.template.today("yyyy") %>;\n' +
		' * Licensed GPLv2+\n' +
		' */\n'
	},
	main: {
		files: {
			'assets/js/customizer.js': 'assets/js/customizer.js',
			'assets/js/foundation.js': 'assets/js/foundation.js',
			'assets/js/html5shiv.js': 'assets/js/html5shiv.js',
			'assets/js/skip-link-focus-fix.js': 'assets/js/skip-link-focus-fix.js',
			'assets/js/theme.js': 'assets/js/theme.js'

		}
	}
};
