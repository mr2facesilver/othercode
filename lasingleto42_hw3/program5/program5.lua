local status, err = pcall(function()
	env = assert (require"luasql.mysql".mysql(), "can't load library")
	-- connect to data source
	conn = assert (env:connect("accident_db", "root", "coursework"), "cant connect to database")
	cur = assert( con:execute "put a query here","error executing query")
	end)
if not status then
	print("Error: " ..err)
	os.exit()
end

row = cur:fetch ( {}, "a") 
while row do
	print(string.format("Name: %s", row.name))
	row = cur:fetch ( row, "a") 
end
cur:close()
con:close()
env:close()
