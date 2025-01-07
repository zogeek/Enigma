/* eslint-disable react/prop-types */
import "./List.css";

export default function List({ list, onRemoveItem }) {
    return (
        <ul className="list">
            {list.map((item) => (
                <Item
                    key={item.objectID}
                    {...item}
                    onRemoveItem={onRemoveItem}
                />
            ))}
        </ul>
    );
}

function Item({
    objectID,
    url,
    title,
    author,
    num_comments,
    points,
    onRemoveItem,
}) {
    return (
        <li className="list-item">
            <a href={url} target="_blank" rel="noopener noreferrer">
                {title}
            </a>
            <span>Auteur : {author} </span>
            <p>
                Comments : {num_comments} | Points : {points}
            </p>
            <button onClick={() => onRemoveItem(objectID)}>Delete</button>
        </li>
    );
}
