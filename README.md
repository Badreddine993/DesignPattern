# C++ Design Patterns & Concepts Lab

A comprehensive workspace for learning, testing, and experimenting with C++ design patterns and advanced concepts.

## 📁 Project Structure

```
DesignPatternsCpp/
├── patterns/                 # Design Patterns implementations
│   ├── creational/          # Creational patterns
│   ├── structural/          # Structural patterns
│   └── behavioral/          # Behavioral patterns
├── concepts/                # Modern C++ concepts
│   ├── templates/           # Template programming
│   ├── memory/              # Memory management
│   ├── concurrency/         # Multi-threading & async
│   └── stl/                 # STL usage patterns
├── experiments/             # Your personal experiments
├── tests/                   # Unit tests
├── examples/                # Complete working examples
├── docs/                    # Documentation and notes
└── build/                   # Build artifacts (auto-generated)
```

## 🚀 Getting Started

1. **Build the project:**
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

2. **Run specific pattern:**
   ```bash
   ./build/patterns/creational/singleton
   ```

3. **Run all tests:**
   ```bash
   make test
   ```

## 📚 Learning Path

### Phase 1: Basic Patterns
- [ ] Singleton
- [ ] Factory Method
- [ ] Observer
- [ ] Strategy

### Phase 2: Advanced Patterns
- [ ] Decorator
- [ ] Command
- [ ] State
- [ ] Visitor

### Phase 3: Modern C++ Concepts
- [ ] RAII
- [ ] Smart Pointers
- [ ] Move Semantics
- [ ] Templates & Concepts

## 🧪 Experiment Guidelines

1. **Create new experiments** in the `experiments/` folder
2. **Document your findings** in the `docs/` folder
3. **Write tests** for your implementations
4. **Compare different approaches** side by side

## 📝 Notes

- Each pattern should have a clear example and explanation
- Include both basic and advanced implementations
- Document performance implications where relevant
- Add real-world use cases for each pattern
