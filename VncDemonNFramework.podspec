Pod::Spec.new do |s|
  s.name         = 'VncDemonNFramework'
  s.version      = '1.0.0'
  s.summary      = 'A short description of VncDemonNFramework.'
  s.description  = 'A detailed description of VncDemonNFramework.'
  s.homepage     = 'https://github.com/johnnyleba/skccc'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'SK' => 'your.email@example.com' }
  s.source       = { :git => 'https://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@github.com/johnnyleba/skccc.git', :tag => '1.0.0' }
  s.platform     = :ios, '10.0'
  s.vendored_frameworks = 'VncDemonNFramework.framework'
  s.resources    = 'VncDemonNFramework.framework/vncwww/**/*'
end
