module.exports = {
	/**
	 * grunt-browser-sync
	 *
	 * Live CSS reload & Browser Syncing
	 *
	 * @link https://www.npmjs.com/package/grunt-browser-sync
	 */
	dev: {
		bsFiles: {
			src: [
				'*.php',
				'**/*.php',
				'Gruntfile.js',
				'js/*.js',
				'*.css',
				'css/*.css'
			]
		},
		options: {
			watchTask: true,
			debugInfo: true,
			logConnections: true,
			notify: true,
			proxy: 'tiffin.prod.dd:8083',
			ghostMode: {
				scroll: true,
				links: true,
				forms: true
			}
		}
	}
};
