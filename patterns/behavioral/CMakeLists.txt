# Behavioral Patterns
# Add your pattern implementations here as you create them

# Observer Pattern - Ready to use!
add_executable(observer observer.cpp)
target_link_libraries(observer Threads::Threads)

# Example: When you create strategy.cpp, uncomment this:
# add_executable(strategy strategy.cpp)
# target_link_libraries(strategy Threads::Threads)
