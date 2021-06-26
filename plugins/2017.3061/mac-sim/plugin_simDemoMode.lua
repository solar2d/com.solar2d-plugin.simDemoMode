local Library = require "CoronaLibrary"
-- Create library
local lib = Library:new{ name='plugin.simDemoMode', publisherId='com.solar2d' }

-------------------------------------------------------------------------------
-- BEGIN (Insert your implementation starting here)
-------------------------------------------------------------------------------

lib.init = function(key)
	print( '[plugin.simDemoMode]: this plugin works only on Windows' )
end

return lib
