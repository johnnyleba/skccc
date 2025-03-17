Pod::Spec.new do |s|
  s.name         = 'VncDemonNFramework'
  s.version      = '1.0.33'
  s.summary      = 'A short description of VncDemonNFramework.'
  s.description  = 'A detailed description of VncDemonNFramework.'
  s.homepage     = 'https://github.com/johnnyleba/skccc'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'SK' => 'your.email@example.com' }
  s.source       = {"http": "https://xdata.samkoonyun.com/ota/admin/3.0/git/VncDemonNFramework.zip", "type": "zip" }
  s.platform     = :ios, '10.0'
  s.vendored_frameworks = 'VncDemonNFramework.framework'
  s.resources    = 'VncDemonNFramework.framework/vncwww/**/*'
end
