module.exports = {
	/**
	 * grunt-contrib-clean
	 *
	 * Clean files and folders.
	 *
	 * @link https://www.npmjs.com/package/grunt-contrib-clean
	 */
	pre: ['*.map', 'css/*.{css,map}'],
	main: ['dist/<%= package.name %>']
};
