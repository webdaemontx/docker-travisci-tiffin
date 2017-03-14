module.exports = {
	/**
	 * grunt-sass
	 *
	 * Compile Sass to CSS using node-sass
	 *
	 * @link https://www.npmjs.com/package/grunt-sass
	 */
	dist: {
		options: {
			sourceMap: true,
			// @link https://make.wordpress.org/core/handbook/best-practices/coding-standards/css/
			indentedSyntax: true,
			indentType: 'tab',
			indentWidth: '1',
			outputStyle: 'expanded'
		},
		files: {
			'css/tiffin_custom.css': 'sass/tiffin_custom.scss'
			// 'css/wetkit_bootstrap.css': 'sass/wetkit_bootstrap.styles.scss'
		}
	}
};
