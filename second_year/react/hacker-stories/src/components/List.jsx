/* eslint-disable react/prop-types */
export default function List(props) {
    return (
        <ul>
            {props.list.map((item) => (
                <Item key={item.id} {...item} />
            ))}
        </ul>
    );
}

function Item(props) {
    return (
        <li>
            <a href={props.url} target="_blank" rel="noopener noreferrer">
                {props.title}
            </a>
            <p>
                {props.author} | {props.num_comments} comments | {props.points}{" "}
                points
            </p>
        </li>
    );
}
