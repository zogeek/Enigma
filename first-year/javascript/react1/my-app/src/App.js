import React, { Component } from "react";
import TodoList from "./TodoList";
import TodoItems from "./TodoItems";
import "./App.css";

class App extends Component {
  inputElement = React.createRef();
  constructor() {
    super();
    this.state = {
      items: [],
      currentItem: { text: "", key: "" },
    };
  }
  addItem = (e) => {
    e.preventDefault();
    const newItem = this.state.currentItem;
    if (newItem.text !== "") {
      console.log(newItem);
      const items = [...this.state.items, newItem];
      this.setState({
        items: items,
        currentItem: { text: "", key: "" },
      });
    }
  };

  handleInput = (e) => {
    const itemText = e.target.value;
    const currentItem = { text: itemText, key: Date.now() };
    this.setState({
      currentItem,
    });
  };

  deleteItem = (key) => {
    const filteredItems = this.state.items.filter((item) => {
      return item.key !== key;
    });
    this.setState({
      items: filteredItems,
    });
  };

  createTasks = (item) => {
    return (
      <li key={item.key} onClick={() => this.props.deleteItem(item.key)}>
        {item.text}
      </li>
    );
  };

  render() {
    return (
      <div className="App">
        <TodoList
          addItem={this.addItem}
          inputElement={this.inputElement}
          handleInput={this.handleInput}
          currentItem={this.state.currentItem}
        />
      </div>
    );
  }
}

export default App;