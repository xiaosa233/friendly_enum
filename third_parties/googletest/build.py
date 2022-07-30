class googletest:
    def __init__(self, config):
        self.include_dirs = ['include']

        config_dir_name = 'Debug' if config.configuration == config.Configuration.DEBUG else 'Release'
        if config.system == config.System.LINUX:
            self.lib_dirs = [
                'lib/linux/' + config_dir_name
            ]
            self.libs = [
                'libgtest.a',
                'libgtest_main.a',
            ]
            self.system_libs = [
                'pthread',
            ]
        elif config.system == config.System.WINDOWS:
            self.lib_dirs = [
                'lib/windows/' + config_dir_name,
            ]
            self.libs = ['*.lib']

