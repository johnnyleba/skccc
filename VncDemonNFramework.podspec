Pod::Spec.new do |s|
  s.name         = 'VncDemonNFramework'
  s.version      = '1.0.28'
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
