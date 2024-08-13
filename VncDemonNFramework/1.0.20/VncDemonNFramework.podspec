Pod::Spec.new do |s|
  s.name         = 'VncDemonNFramework'
  s.version      = '1.0.20'
  s.summary      = 'A short description of VncDemonNFramework.'
  s.description  = 'A detailed description of VncDemonNFramework.'
  s.homepage     = 'https://github.com/johnnyleba/skccc'
  s.source       = { :git => 'https://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@github.com/johnnyleba/skccc.git', :tag => '1.0.0' }
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'Your Name' => 'your.email@example.com' }
  s.platform     = :ios, '10.0'
  s.ios.deployment_target = '10.0'
  s.vendored_frameworks = 'VncDemonNFramework.framework'
  s.resources    = 'VncDemonNFramework.framework/vncwww/**/*'
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
