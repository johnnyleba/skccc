Pod::Spec.new do |s|
  s.name         = 'VncDemonNFramework'
  s.version      = '1.0.35'
  s.summary      = 'A short description of VncDemonNFramework.'
  s.description  = 'A longer description of c1 with usage and features.'
  s.homepage     = 'https://github.com/johnnyleba/c1'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'Your Name' => 'your@email.com' }
  s.source       = {"http": "https://xdata.samkoonyun.com/ota/admin/3.0/git/VncDemonNFramework.zip", "type": "zip"  }
  s.platform     = :ios, '10.0'
  s.ios.deployment_target = '10.0'
  s.vendored_frameworks = 'VncDemonNFramework.framework'
  s.resources    = ['VncDemonNFramework.framework/**/*']
  s.requires_arc = true
  s.user_target_xcconfig = {
    'GENERATE_INFOPLIST_FILE' => 'YES'
  }
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'arm64',  # Only valid arch is arm64
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64',  # Exclude arm64 for simulator
    'ARCHS' => 'arm64',  # Only build for arm64
    'ONLY_ACTIVE_ARCH' => 'YES',
    'GENERATE_INFOPLIST_FILE' => 'YES'
  }
end

